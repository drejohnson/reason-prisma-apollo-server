// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';


var UserParent = /* module */[];

var user = {
  id: (function (parent) {
      return parent.id;
    }),
  email: (function (parent) {
      return parent.email;
    }),
  name: (function (parent) {
      return parent.name;
    }),
  posts: (function (parent, _, ctx) {
      return ctx.db.user({
                    id: parent.id
                  }).posts();
    })
};

exports.UserParent = UserParent;
exports.user = user;
/* No side effect */
