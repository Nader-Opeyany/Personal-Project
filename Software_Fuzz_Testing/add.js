import { createVendiaClient } from '@vendia/client'

const client = createVendiaClient({
  apiUrl: `https://r4a3jwtij7.execute-api.us-west-1.amazonaws.com/graphql/`,
  websocketUrl: `wss://sfsug601zd.execute-api.us-west-1.amazonaws.com/graphql`,
  apiKey: process.env.VENDIA_API_KEY, ESWp6bZVHE88YRqXwzFpbbTpmDtEQYe8t9fv15AjPYk8// <---- API key
})