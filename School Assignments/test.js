//refrence code from here: https://dev.to/oyetoket/fastest-way-to-generate-random-strings-in-javascript-2k5a
const superRandom = function (length, iterableStrTest="") {
    iterableStrTest += Math.random().toString(20).substring(2, length); //Random integers are created here from ints
    if (iterableStrTest.length > length) return iterableStrTest.slice(0, length);
    return superRandom(length, iterableStrTest);
  };

  var testCase = superRandom(11,"")
  console.log(testCase)
  console.log("in test.js")