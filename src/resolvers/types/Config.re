module Prisma = {
  type t;
  [@bs.val] [@bs.module "./generated/prisma-client"]
  external prisma: t = "prisma";
};

module Context = {
  [@bs.deriving abstract]
  type t = {db: Prisma.t};
};

module DataSources = {
  type t;
};

module Resolvers = {
  type t;
};