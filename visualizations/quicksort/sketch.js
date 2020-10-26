//alex shelton 




let i = 0;
let w = 5;
let values = []
let states = []

function setup(){
  createCanvas(600,600);
  values = new Array(floor(width / w));
  for(let i = 0; i < values.length; i++) {
    values[i] = random(height);
    states[i] = -1;
  }
  quickSort(values, 0, values.length - 1);
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function swap(arr, x, y){
  await sleep(75);
  let tmp = arr[x];
  arr[x] = arr[y];
  arr[y] = tmp;
}


async function partition(arr, low, high) {
  for(let i = low; i < high; i++) states[i] = 1;
  let pivot = arr[high]; // using the last index as the pivot
  let smaller = low - 1;
  states[smaller] = 0;

  for(let i = low; i < high; i++) {
    if(arr[i] < pivot){ 
      states[smaller] = -1;
      smaller += 1;
      await swap(arr, smaller, i);
      states[smaller] = 0;
    }
  }
  await swap(arr, smaller + 1, high);

  for(let i = low; i < high; i++) {
    if (i != smaller) states[i] = -1;
  }


  return smaller+1;
}



async function quickSort(arr, low, high) {
  if(low < high) {
    let pi = await partition(arr, low, high);
    states[pi] = -1;
    await Promise.all([
    quickSort(arr, low, pi - 1),
    quickSort(arr, pi + 1, high)
    ]);
  } else return;
}




function draw() {
  background(50);
  for (let i = 0; i < values.length; i++) {
    noStroke();
    if (states[i] == 0) {
      fill('#ff0000');
    } else if (states[i] == 1) {
      fill('#00def0');
    } else {
      fill(255);
    }
    rect(i * w, height - values[i], w, values[i]);
  }
}
