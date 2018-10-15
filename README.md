# GraphQL Api Server build with Prisma & Apollo Server

> Basic GraphQL Api Server build with [Prisma](https://www.prisma.io/) & [Apollo Server](https://github.com/apollographql/apollo-server) - based on the node-graphql example from [prisma-examples](https://github.com/prisma/prisma-examples/tree/master/node-graphql).

## Quick start

* Install dependencies: `yarn`
* Start graphql server: run `yarn build:bsb` followed by `yarn start`, the server should be running at: http://localhost:4444.

## Setup your own Prisma service: 

* Delete the directories: `./prisma` and `./src/generated`
* Follow [Setting up Prisma](https://www.prisma.io/docs/get-started/01-setting-up-prisma-new-database-a002/) guide to initialize and deploy a Prisma service. When asked choose "Javascript-client".
