var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

const { once } = require("../src/code_2666.js");

fn = (a, b, c) => a + b + c;
onceFn = once(fn);
expect(onceFn(1, 2, 3)).to.equal(6);
expect(onceFn(2, 3, 6)).to.equal(undefined);

fn = (a, b, c) => a * b * c;
onceFn = once(fn);
expect(onceFn(5, 7, 4)).to.equal(140);
expect(onceFn(2, 3, 6)).to.equal(undefined);
expect(onceFn(4, 6, 8)).to.equal(undefined);
