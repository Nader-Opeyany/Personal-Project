import {add} from './add.js'
/*

//jest functionality
test('Checks the sent JSON: ', ()=>{
    expect(addResponse.result.item).toBe(itemObj)
  });*/
  const input = 'yuv265233i23w';

test('input matches output', () => {
  expect(add(input)).toBe(input);
});