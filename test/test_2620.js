var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

const { createCounter } = require("../src/code_2620.js");

counter = createCounter(10);
expect(counter()).to.equal(10);
expect(counter()).to.equal(11);
expect(counter()).to.equal(12);

counter = createCounter(-2);
expect(counter()).to.equal(-2);
expect(counter()).to.equal(-1);
expect(counter()).to.equal(0);
expect(counter()).to.equal(1);
expect(counter()).to.equal(2);
