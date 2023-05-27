var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

const { curry } = require("../src/code_2632.js");

function sum(a, b, c) {
  return a + b + c;
}
const curriedSum = curry(sum);
expect(curriedSum(1)(2)(3)).to.equal(6);
expect(curriedSum(1, 2)(3)).to.equal(6);
expect(curriedSum()()(1, 2, 3)).to.equal(6);

fn = function life() {
  return 42;
};
const curriedLife = curry(fn);
expect(curriedLife()).to.equal(42);
