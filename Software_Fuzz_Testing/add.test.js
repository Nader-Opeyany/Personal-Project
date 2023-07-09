const { describe } = require('node:test');
const add = require('./add')
const  superRandom  = require('./generateMalformedInput');


  //variable declerations
  var itemObj =  superRandom(10);
  var recommendedLocationObj = superRandom(10);

  //jest functionality

  test('Test result, ensuring the correct data is sent through SDK', async () => {
    return add(itemObj,recommendedLocationObj).then(data => {
      expect(data.result.item).toBe(itemObj);
    });
  });

