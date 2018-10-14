[@bs.deriving abstract]
type t = {
  [@bs.as "Query"]
  query: Query.queryOutput,
  [@bs.as "Mutation"]
  mutation: Mutation.mutationOutput,
  [@bs.as "Post"]
  post: Post.postOutput,
  [@bs.as "User"]
  user: User.userOutput,
};

let resolvers =
  t(
    ~query=Query.query,
    ~mutation=Mutation.mutation,
    ~post=Post.post,
    ~user=User.user,
  );