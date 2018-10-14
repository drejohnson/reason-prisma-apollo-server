module type Config = {
  type resolvers;
  type context;
  type datasources;
};

module Make = (Config: Config) => {
  type queryString;

  type graphqlServer;

  type gql_ = (. string) => queryString;

  [@bs.deriving abstract]
  type response = {url: string};

  [@bs.deriving abstract]
  type apolloServerProps = {
    typeDefs: string,
    resolvers: Config.resolvers,
    datasources: Js.nullable(Config.datasources),
    context: Js.nullable(Config.context),
    engine: Js.nullable(bool),
  };

  [@bs.deriving abstract]
  type listenProps = {port: int};

  [@bs.module "apollo-server"] external gql: gql_ = "gql";

  [@bs.module "apollo-server"] [@bs.new]
  external makeApolloServer: apolloServerProps => graphqlServer =
    "ApolloServer";

  [@bs.send]
  external listen: (graphqlServer, listenProps) => Js.Promise.t(response) =
    "";

  let createApolloServer =
      (~typeDefs, ~resolvers, ~datasources=?, ~context=?, ~engine=?, ()) => {
    let apolloServerOptions =
      apolloServerProps(
        ~typeDefs,
        ~resolvers,
        ~datasources=Js.Nullable.fromOption(datasources),
        ~context=Js.Nullable.fromOption(context),
        ~engine=Js.Nullable.fromOption(engine),
      );
    makeApolloServer(apolloServerOptions);
  };
};