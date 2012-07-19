var tap = require("tap"),
    weak = require("weak"),
    gc = require("../");

tap.test("basic", function(t){
    t.plan(1);

    var obj = { a: 3 },
        ref = weak(obj, function(){
            t.ok(3, this.a);
            t.end();
        });

    obj = null;

    gc();
});
