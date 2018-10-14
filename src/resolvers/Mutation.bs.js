// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';


var MutationParent = /* module */[];

var mutation = {
  createDraft: (function (_, args, ctx) {
      return ctx.db.createPost({
                  title: args.title,
                  content: args.content,
                  author: {
                    connect: {
                      email: args.authorEmail
                    }
                  }
                });
    }),
  deletePost: (function (_, args, ctx) {
      return ctx.db.deletePost({
                  id: args.id
                });
    }),
  publish: (function (_, args, ctx) {
      return ctx.db.updatePost({
                  where: {
                    id: args.id
                  },
                  data: {
                    isPublished: false
                  }
                });
    })
};

exports.MutationParent = MutationParent;
exports.mutation = mutation;
/* No side effect */