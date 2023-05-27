var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

const { reduce } = require("../src/code_2626.js");

expect(
  reduce(
    (nums = [1, 2, 3, 4]),
    (fn = function sum(accum, curr) {
      return accum + curr;
    }),
    (init = 0)
  )
).to.equal(10);

expect(
  reduce(
    (nums = [1, 2, 3, 4]),
    (fn = function sum(accum, curr) {
      return accum + curr * curr;
    }),
    (init = 100)
  )
).to.equal(130);

expect(
  reduce(
    (nums = []),
    (fn = function sum(accum, curr) {
      return 0;
    }),
    (init = 25)
  )
).to.equal(25);
