/*
二分查找总结：套路就是while里面if-else条件的修改，以及return left 还是return right 
最复杂的是 "第一个相等" 和 "第一个相等"  
// 这里必须是 <=
while (left <= right) {
    int mid = (left + right) / 2;
    if (array[mid] ? key) {
        //... right = mid - 1;
    }
    else {
        // ... left = mid + 1;
    }
}
return xxx;
*/
/************************************************************************************************/ 


// 标准二分查找，找到该值在数组中的下标，否则为-1
static int binarySerach(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == key) {      //查找等于，需要 if - else if - else  
            return mid;
        }
        else if (array[mid] > key) {
        	right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}

// 查找第一个相等的元素
static int findFirstEqual(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] >= key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    if (left < array.length && array[left] == key) { //比第一个等于或者大于，多了一个条件
        return left;
    }
    
    return -1;
}

// 查找最后一个相等的元素
static int findLastEqual(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > key) { 
            right = mid - 1;  
        }
        else {
            left = mid + 1;
        }
    }
    if (right >= 0 && array[right] == key) {  //比最后一个等于或者小于，多了一个条件 
        return right;
    }

    return -1;
}

/*************************************************************************************************/
// return right 
 
// 查找最后一个等于或者小于key的元素
static int findLastEqualSmaller(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}

// 查找最后一个小于key的元素
static int findLastSmaller(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] >= key) {   //相比等于小于，只有这个条件修改 
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}

/*************************************************************************************************/
// return left 
 
// 查找第一个等于或者大于key的元素
static int findFirstEqualLarger(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] >= key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

// 查找第一个大于key的元素
static int findFirstLarger(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > key) {   //相比等于大于，只有这个条件修改 
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

