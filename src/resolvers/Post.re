module PostParent = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "id"]
    id_: string,
    [@bs.as "createdAt"]
    createdAt_: string,
    [@bs.as "updatedAt"]
    updatedAt_: string,
    [@bs.as "isPublished"]
    isPublished_: bool,
    [@bs.as "title"]
    title_: string,
    [@bs.as "content"]
    content_: string,
    [@bs.as "author"]
    author_: string,
  };
};

type args;

[@bs.deriving abstract]
type postParentArgs = {
  [@bs.as "id"]
  id_: PostParent.t,
};

[@bs.deriving abstract]
type postOutput = {
  id: PostParent.t => string,
  createdAt: PostParent.t => string,
  updatedAt: PostParent.t => string,
  isPublished: PostParent.t => bool,
  title: PostParent.t => string,
  content: PostParent.t => string,
  author: (postParentArgs, args, Config.Context.t) => string,
};

[@bs.send] external post_: (Config.Prisma.t, postParentArgs) => 'a = "post";

[@bs.send] external author_: unit => 'a = "author";

let post =
  postOutput(
    ~id=parent => parent->PostParent.id_Get,
    ~createdAt=parent => parent->PostParent.createdAt_Get,
    ~updatedAt=parent => parent->PostParent.updatedAt_Get,
    ~isPublished=parent => parent->PostParent.isPublished_Get,
    ~title=parent => parent->PostParent.title_Get,
    ~content=parent => parent->PostParent.content_Get,
    ~author=
      (parent, _arg, ctx) =>
        ctx
        ->Config.Context.dbGet
        ->post_(postParentArgs(~id_=parent->id_Get))
        ->author_,
  );