"use strict";

const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputList = [];

rl.on("line", (answer) => {
  inputList.push(answer);
});

rl.on("close", () => {
  main(inputList);
  process.exit(0);
});

// Write your code here
function main(input) {
  let checkList = [];
  function sum(startIdx) {
    if (checkList.length === 7) {
      const sum = checkList.reduce((acc, cur) => acc + cur, 0);
      if (sum === 100) {
        checkList.sort((a, b) => a - b);
        checkList.forEach((checkItem) => {
          console.log(checkItem);
        });

        process.exit(0);
      }
    }

    for (let i = startIdx + 1; i < 9; i++) {
      checkList.push(+input[i]);
      sum(startIdx + 1);
      checkList.pop();
    }
    return;
  }

  sum(-1);
}
