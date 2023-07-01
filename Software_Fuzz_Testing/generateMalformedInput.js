  const superRandom = function (length, iterableStrTest="") {
    iterableStrTest += Math.random().toString(20).substring(2, length); //Random integers are created here from ints
    if (iterableStrTest.length > length) return iterableStrTest.slice(0, length);
    return superRandom(length, iterableStrTest);
  };

module.exports = superRandom;
  