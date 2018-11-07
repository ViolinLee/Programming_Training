/*
���ֲ����ܽ᣺��·����while����if-else�������޸ģ��Լ�return left ����return right 
��ӵ��� "��һ�����" �� "��һ�����"  
// ��������� <=
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


// ��׼���ֲ��ң��ҵ���ֵ�������е��±꣬����Ϊ-1
static int binarySerach(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // ��������� <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == key) {      //���ҵ��ڣ���Ҫ if - else if - else  
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

// ���ҵ�һ����ȵ�Ԫ��
static int findFirstEqual(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // ��������� <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] >= key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    if (left < array.length && array[left] == key) { //�ȵ�һ�����ڻ��ߴ��ڣ�����һ������
        return left;
    }
    
    return -1;
}

// �������һ����ȵ�Ԫ��
static int findLastEqual(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // ��������� <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > key) { 
            right = mid - 1;  
        }
        else {
            left = mid + 1;
        }
    }
    if (right >= 0 && array[right] == key) {  //�����һ�����ڻ���С�ڣ�����һ������ 
        return right;
    }

    return -1;
}

/*************************************************************************************************/
// return right 
 
// �������һ�����ڻ���С��key��Ԫ��
static int findLastEqualSmaller(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // ��������� <=
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

// �������һ��С��key��Ԫ��
static int findLastSmaller(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // ��������� <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] >= key) {   //��ȵ���С�ڣ�ֻ����������޸� 
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
 
// ���ҵ�һ�����ڻ��ߴ���key��Ԫ��
static int findFirstEqualLarger(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // ��������� <=
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

// ���ҵ�һ������key��Ԫ��
static int findFirstLarger(int[] array, int key) {
    int left = 0;
    int right = array.length - 1;

    // ��������� <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > key) {   //��ȵ��ڴ��ڣ�ֻ����������޸� 
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

