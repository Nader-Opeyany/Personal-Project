const add = require('./add')
const  superRandom  = require('./generateMalformedInput');

//variable declerations
var itemObj =  superRandom(10);
var recommendedLocationObj = superRandom(10);

//jest functionality
test('Working code UwU', () => {
  return add(itemObj,recommendedLocationObj).then(data => {
    expect(data.result.item).toBe(itemObj);
  });
});
  
