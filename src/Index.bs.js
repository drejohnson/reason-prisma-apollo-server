// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var GraphqlImport = require("graphql-import");
var PrismaClient = require("./generated/prisma-client");
var Resolvers$ReasonApolloServerPrisma = require("./resolvers/Resolvers.bs.js");
var ApolloServer$ReasonApolloServerPrisma = require("./ffi/ApolloServer.bs.js");

var Server = ApolloServer$ReasonApolloServerPrisma.Make(/* module */[]);

var typeDefs = GraphqlImport.importSchema("./src/schema.graphql");

var server = Curry._6(Server[/* createApolloServer */0], typeDefs, Resolvers$ReasonApolloServerPrisma.resolvers, undefined, {
      db: PrismaClient.prisma
    }, undefined, /* () */0);

server.listen({
        port: 4444
      }).then((function (res) {
        return Promise.resolve((console.log("Server ready at " + res.url), /* () */0));
      }));

exports.Server = Server;
exports.typeDefs = typeDefs;
exports.server = server;
/* Server Not a pure module */