import { createVendiaClient } from '@vendia/client';

const client = createVendiaClient({
  apiUrl: `https://r4a3jwtij7.execute-api.us-west-1.amazonaws.com/graphql/`,
  websocketUrl: `wss://sfsug601zd.execute-api.us-west-1.amazonaws.com/graphql`,
  apiKey:  'ESWp6bZVHE88YRqXwzFpbbTpmDtEQYe8t9fv15AjPYk8',// <---- API key

  
});
const { entities } = client

async function add(){
  // Add a new "product"
const before = Date.now();
const addResponse = await entities.shoppingList.add({
  item: 'for demo',
  recommendedLocation:'for demoTwo'
},
{
  synchMode: 'ASYNC'
})
const after = Date.now()
console.log(`This is elapsed Time: ${(after-before)/1000} seconds`)

};


//Calling functions to run here
add();
