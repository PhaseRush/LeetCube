var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

const { createHelloWorld } = require("../src/code_2667.js");

const f = createHelloWorld();
expect(f()).to.equal("Hello World");
