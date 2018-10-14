module UserParent = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "id"]
    id_: string,
    [@bs.as "email"]
    email_: string,
    [@bs.as "name"]
    name_: string,
    [@bs.as "posts"]
    posts_: array(Post.PostParent.t),
  };
};

type args;

[@bs.deriving abstract]
type userParentArgs = {
  [@bs.as "id"]
  id_: UserParent.t,
};

[@bs.deriving abstract]
type userOutput = {
  id: UserParent.t => string,
  email: UserParent.t => string,
  name: UserParent.t => string,
  posts: (userParentArgs, args, Config.Context.t) => string,
};

[@bs.send] external user_: (Config.Prisma.t, userParentArgs) => 'a = "user";

[@bs.send] external posts_: unit => 'a = "posts";

let user =
  userOutput(
    ~id=parent => parent->UserParent.id_Get,
    ~email=parent => parent->UserParent.email_Get,
    ~name=parent => parent->UserParent.name_Get,
    ~posts=
      (parent, _arg, ctx) =>
        ctx
        ->Config.Context.dbGet
        ->user_(userParentArgs(~id_=parent->id_Get))
        ->posts_,
  );