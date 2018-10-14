module QueryParent = {
  [@bs.deriving abstract]
  type t;
};

[@bs.deriving abstract]
type postsWhereInput = {isPublished: bool};

/* Todo: Add type sig */
[@bs.deriving abstract]
type postsOrderByInput;

[@bs.deriving abstract]
type postsArgs = {
  [@bs.optional]
  where: postsWhereInput,
  [@bs.optional]
  orderBy: postsOrderByInput,
  [@bs.optional]
  skip: int,
  [@bs.optional]
  after: string,
  [@bs.optional]
  before: string,
  [@bs.optional]
  first: int,
  [@bs.optional]
  last: int,
};

[@bs.deriving abstract]
type postArgs = {id: Post.PostParent.t};

type args;

[@bs.send] external posts_: (Config.Prisma.t, postsArgs) => 'a = "posts";

[@bs.send] external post_: (Config.Prisma.t, postArgs) => 'a = "post";

[@bs.deriving abstract]
type queryOutput = {
  feed: (QueryParent.t, args, Config.Context.t) => string,
  drafts: (QueryParent.t, args, Config.Context.t) => string,
  post: (QueryParent.t, postArgs, Config.Context.t) => string,
};

let query =
  queryOutput(
    ~feed=
      (_parent, _args, ctx) =>
        ctx
        ->Config.Context.dbGet
        ->posts_(postsArgs(~where=postsWhereInput(~isPublished=true), ())),
    ~drafts=
      (_parent, _args, ctx) =>
        ctx
        ->Config.Context.dbGet
        ->posts_(postsArgs(~where=postsWhereInput(~isPublished=false), ())),
    ~post=
      (_parent, args, ctx) =>
        ctx->Config.Context.dbGet->post_(postArgs(~id=args->idGet)),
  );