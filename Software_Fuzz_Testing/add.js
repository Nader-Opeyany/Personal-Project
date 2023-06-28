import { createVendiaClient } from '@vendia/client';
import { superRandom } from './generateMalformedInput.js'


const client = createVendiaClient({
  apiUrl: `https://r4a3jwtij7.execute-api.us-west-1.amazonaws.com/graphql/`,
  websocketUrl: `wss://sfsug601zd.execute-api.us-west-1.amazonaws.com/graphql`,
  apiKey:  'ESWp6bZVHE88YRqXwzFpbbTpmDtEQYe8t9fv15AjPYk8',// <---- API key

  
});
const { entities } = client;
//Addresponse
var itemObj = superRandom(10);
var recommendedLocationObj = superRandom(10);
async function add(){
  // Add a new "product"
const before = Date.now();
const addResponse = await entities.shoppingList.add({
  item: itemObj,
  recommendedLocation: recommendedLocationObj,
  //timestampAdded: `${String((before/1000))} seconds`
},
{
  synchMode: 'ASYNC'
})
const after = Date.now();
//console.log(`This is elapsed Time: ${(after-before)/1000} seconds`)
console.log(addResponse.result.item);

};


//Calling functions to run here
add();

