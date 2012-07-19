var gc = require("bindings")("gc.node");

module.exports = (global.gc ? global.gc : gc.collect);
