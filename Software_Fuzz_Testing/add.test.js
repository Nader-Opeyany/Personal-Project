const add = require('./add')
const  superRandom  = require('./generateMalformedInput');

for( i = 0;i<10<i++;){
  //variable declerations
  var itemObj =  superRandom(10);
  var recommendedLocationObj = superRandom(10);

  //jest functionality
  test('Working code UwU', () => {
    return add(itemObj,recommendedLocationObj).then(data => {
      expect(data.result.item).toBe(itemObj);
    });
  });
};
