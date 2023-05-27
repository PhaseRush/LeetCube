var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

const { sleep } = require("../../src/js/code_2621.js");

delta = 10;
millis = 100;
t = Date.now();
expect(sleep(millis).then(() => Date.now() - t)).to.be.eventually.closeTo(
  millis,
  delta
);

millis = 200;
t = Date.now();
expect(sleep(millis).then(() => Date.now() - t)).to.be.eventually.closeTo(
  millis,
  delta
);
