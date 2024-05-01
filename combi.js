function combination(n, arr) {
  const combi = (depth, s) => {
    if (depth === n) {
      answer.push(temp.slice());
      return;
    }

    for (let i = s; i < arr.length; i++) {
      temp[depth] = arr[i];
      combi(depth + 1, i + 1);
    }
  }

  const answer = [];
  const temp = Array(n);
  combi(0, 1);
  return answer;
}

console.log(combination(1, [-1, 1, 2, 3, 4, 5]));