//Time Complexity - O(n)
//Space Complexity - O(1)

const containerWithMostWater = (height) => {

  //Initialize pointers and maxArea Variable
  let l = 0;
  let r = height.length - 1;
  let maxArea = 0;

  //Loop till pointers equal each other
  while (l < r) {
    
    //Calculate the area for each 2 bars
    let area = Math.min(height[l], height[r]) * (r - l);
    
    //Set maxArea if current area is greater than itself
    if (area > maxArea) {
      maxArea = area;
    }
    
    //Move pointer pointing to lower value as only that can increase our area
    if (height[l] < height[r]) {
      l++;
    } else {
      r--;
    }
  }

  return maxArea;
};

const test = [1, 8, 6, 2, 5, 4, 8, 3, 7];

console.log(containerWithMostWater(test));
