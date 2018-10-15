[@bs.module "graphql-import"]
external importSchema: (. string) => string = "importSchema";

module Server =
  ApolloServer.Make({
    type resolvers = Resolvers.t;
    [@bs.deriving abstract]
    type context = Config.Context.t;
    type datasources = Config.DataSources.t;
  });

let typeDefs = importSchema(. "./src/schema.graphql");
let server =
  Server.createApolloServer(
    ~typeDefs,
    ~resolvers=Resolvers.resolvers,
    ~context=Config.Context.t(~db=Config.Prisma.prisma),
    (),
  );

server->(Server.listen(Server.listenProps(~port=4444)))
|> Js.Promise.then_(res =>
     Js.log("Server ready at " ++ res->Server.urlGet)->Js.Promise.resolve
   );