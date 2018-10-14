module MutationParent = {
  [@bs.deriving abstract]
  type t;
};

[@bs.deriving abstract]
type postsCreateArgs = {
  [@bs.as "title"]
  title_: string,
  [@bs.as "content"]
  content_: string,
  [@bs.as "authorEmail"]
  authorEmail_: string,
};

[@bs.deriving abstract]
type connectInput = {email: string};

[@bs.deriving abstract]
type userCreateInput = {
  [@bs.optional]
  connect: connectInput,
};

[@bs.deriving abstract]
type postsCreateInput = {
  title: string,
  content: string,
  author: userCreateInput,
};

[@bs.deriving abstract]
type input = {id: Post.PostParent.t};

[@bs.deriving abstract]
type postDeleteArgs = input;

[@bs.deriving abstract]
type postUpdateInput = {
  [@bs.as "id"]
  id_: string,
};

[@bs.deriving abstract]
type postDataInput = {
  [@bs.as "isPublished"]
  isPublished_: bool,
};

[@bs.deriving abstract]
type postUpdateArgs = {
  where: postUpdateInput,
  data: postDataInput,
};

[@bs.send]
external createPost_: (Config.Prisma.t, postsCreateInput) => 'a = "createPost";

[@bs.send]
external deletePost_: (Config.Prisma.t, postDeleteArgs) => 'a = "deletePost";

[@bs.send]
external updatePost_: (Config.Prisma.t, postUpdateArgs) => 'a = "updatePost";

[@bs.deriving abstract]
type mutationOutput = {
  createDraft: (MutationParent.t, postsCreateArgs, Config.Context.t) => string,
  deletePost: (MutationParent.t, postDeleteArgs, Config.Context.t) => string,
  publish: (MutationParent.t, postUpdateInput, Config.Context.t) => string,
};

let mutation =
  mutationOutput(
    ~createDraft=
      (_parent, args, ctx) =>
        ctx
        ->Config.Context.dbGet
        ->createPost_(
            postsCreateInput(
              ~title=args->title_Get,
              ~content=args->content_Get,
              ~author=
                userCreateInput(
                  ~connect=connectInput(~email=args->authorEmail_Get),
                  (),
                ),
            ),
          ),
    ~deletePost=
      (_parent, args, ctx) =>
        ctx->Config.Context.dbGet->deletePost_(input(~id=args->idGet)),
    ~publish=
      (_parent, args, ctx) =>
        ctx
        ->Config.Context.dbGet
        ->updatePost_(
            postUpdateArgs(
              ~where=postUpdateInput(~id_=args->id_Get),
              ~data=postDataInput(~isPublished_=false),
            ),
          ),
  );