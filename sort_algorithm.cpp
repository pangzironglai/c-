#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// 冒泡排序：时间复杂度：O(N^2)  空间复杂度： O（1）

void BubbleSort(vector<int>&nums) {
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j+1]);
		}


	}
}

//  选择排序： 时间复杂度：O(N^2)  空间复杂度：O（1）
void SelectSort(vector<int>&nums) {
	int len = nums.size();
	for (int i = 0; i < len-1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < len; j++) {
			if (nums[j] < nums[minIndex])
				minIndex = j;
		}
		swap(nums[i], nums[minIndex]);
	}
}

// 插入排序： O(N^2) , O(1)

void InsertSort(vector<int>&nums) {
	int len = nums.size();
	for (int i = 1; i < len; i++) {
		for (int j = i; j >= 1; j--) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
			}
		}
	}
}

// 希尔排序： 

void ShellSort(vector<int>& nums) {
	int len = nums.size();
	int gap = len / 2;
	for (int g = gap; g >= 1; g/=2) {
		for (int i = g; i < len; i++) {
			for (int j = i; j -g >= 0 ; j -= g) {
				if (nums[j] < nums[j - g])
					swap(nums[j], nums[j - g]);
			}
		}
	}
	
}


// 快速排序： O(NlogN); O(1)

void QuickSort(vector<int>&nums , int left , int right) {
	if (left < right) {
		int i = left; int j = right;
		int temp = nums[i];
		while (i < j)
		{
			while (i < j && nums[j] > temp)
				j--;
			if (i < j) {
				nums[i] = nums[j];
				i++;
			}
			while (i < j && nums[i] < temp)
				i++;
			if (i < j) {
				nums[j] = nums[i];
				j--;
			}
		}
		nums[i] = temp;
		QuickSort(nums, left, i - 1);
		QuickSort(nums, i + 1, right);
	}
}

// 归并排序  O(NlogN) , O(N)

void merge(vector<int>&nums, int left, int mid, int right) {
	vector<int>temp;
	int p1 = left; int p2 = mid + 1;
	while (p1 <= mid && p2 <= right) {
		if (nums[p1] < nums[p2]) {
			temp.push_back(nums[p1]);
			p1++;
		}
		else {
			temp.push_back(nums[p2]);
			p2++;
		}
	}
	while (p1 <= mid) {
		temp.push_back(nums[p1]);
		p1++;
	}
	while (p2<=right){
		temp.push_back(nums[p2]);
		p2++;
	}
	for (int i = 0; i < temp.size(); i++) {
		nums[left + i] = temp[i];
	}
}

void sorted(vector<int>&nums, int left, int right) {
	if (right - left == 0)
		return;
	int mid = left + (right - left) / 2;
	sorted(nums, left, mid);
	sorted(nums, mid+1, right);
	merge(nums, left, mid, right);

}

void MergeSort(vector<int>&nums) {
	int len = nums.size();
	sorted(nums, 0, len - 1);
}



// 堆排序
//1.先把数组变成一个最大堆
//2.替换第一个和最后一个元素
//3.再把数组整成最大堆

void HeapBuild(vector<int>&nums, int root, int len) {
	int lchild = root * 2 + 1;
	if (lchild < len) {
		int flag = lchild;
		int rchild = lchild + 1;
		if (rchild < len) {
			if (nums[rchild] > nums[flag])
				flag = rchild;
		}
		if (nums[root] < nums[flag]) {
			swap(nums[root], nums[flag]);
			HeapBuild(nums, flag, len);
		}

	}

}

void HeapSort(vector<int>&nums, int len) {
	for (int i = len / 2; i >= 0; i--)
		HeapBuild(nums, i, len);
	for (int j = len - 1; j > 0; --j) {
		swap(nums[0], nums[j]);
		HeapBuild(nums, 0, j);
	}


}

// 计数排序

void CountSort(vector<int>&nums) {
	int min = INT_MAX; int max = INT_MIN;
	for (auto n : nums) {
		if (n > max)
			max = n;
		if (n < min)
			min = n;
	}
	vector<int>count(max - min + 1 , 0);
	for (int i = 0; i < nums.size(); i++) {
		count[nums[i] - min]++;
	}
	int index = 0;
	for (int i = 0; i < count.size(); i++) {
		while (count[i]--) {
			nums[index++] = min + i;
		}
	}
}

// 桶排序
void BucketSort(vector<int>&nums, int bucketSize) {
	int len = nums.size();
	if (len < 2)
		return;
	int min = INT_MAX; int max = INT_MIN;
	for (auto num : nums) {
		max = num > max ? num : max;
		min = num < min ? num : min;
	}
	int BucketCount = (max - min) / bucketSize + 1;
	vector<vector<int>>bucketArr(BucketCount);
	for (int i = 0; i < len; i++) {
		int index = (nums[i] - min) / bucketSize;
		bucketArr[index].push_back(nums[i]);
	}
	nums.clear();
	for (int i = 0; i < BucketCount; i++) {
		int  tlen = bucketArr[i].size();
		sort(bucketArr[i].begin(), bucketArr[i].end());
		for (int j = 0; j < tlen; j++) {
			nums.push_back(bucketArr[i][j]);
		}
	}
}





int main() {
	vector<int>nums = {5,2,6,1,3,4,7,9,8};
	BucketSort(nums,3);
	return 0;
}