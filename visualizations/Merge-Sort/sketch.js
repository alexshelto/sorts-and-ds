

let i = 0;
let w = 10;
let states = []




function setup() {
  createCanvas(800,800);
  values = new Array(floor(width / w));
  for(let i = 0; i < values.length; i++) { 
    values[i] = random(height);
    states[i] = -1;
  }
  mergeSort(values, 0, values.length - 1);
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}


async function merge(arr, l, q, r) {
  let leftLen = q - l + 1;
  let rightLen = (r - q);
  states[q] = 1;

  let left = new Array(leftLen);//= new Array(q-l+1);
  let right = new Array(rightLen);
 
  for(let i = 0; i < leftLen; i++){
    left[i] = arr[l + i];
  }
  for(let j = 0; j < rightLen; j++) {
    right[j] = arr[q + j + 1]; 
  }

  //create begining index for arrays
  let i = 0; //left array
  let j = 0; //right index
  let k = l; //original 

  while(i < leftLen && j < rightLen) {
    if(left[i] <= right[j]) {
      arr[k] = left[i]
      i += 1;
    }
    else {
      arr[k] = right[j];
      j += 1;
    }
    k += 1;
    await sleep(100)
  }

  //should only be called on 1 of the two arrays 
  while(j < rightLen) {
    arr[k] = right[j];
    j += 1;
    k += 1;
    await sleep(100)
  }
  while(i < leftLen) {
    arr[k] = left[i];
    i += 1;
    k += 1;
    await sleep(100)
  }

  for(let i = l; i < r; i++) {
    if (i != q) states[i] = -1;
  }

  


}


async function mergeSort(arr, l, r) {
  if(l < r) {
    let q = floor(l + (r - l) / 2);
    states[q] = 1; //output color purposes
    await Promise.all([
    mergeSort(arr, l, q),
    mergeSort(arr, q + 1, r)
    ]);
    await merge(arr, l, q, r);
  }
}



function draw() {
  background(55);

  for (let i = 0; i < values.length; i++) {
    noStroke();
    console.log(states[i]);
    if (states[i] == 1) {
      fill('#DF2E14');
    } else {
      fill(100);
    }
    console.log(states[i]);
    rect(i * w, height - values[i], w, values[i]);
  }

}
