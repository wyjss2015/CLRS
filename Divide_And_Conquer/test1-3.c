#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct ArrayNode{
	int low;
	int high;
	int maxsum;
};
//暴力求解法;
/*
struct ArrayNode* Find_Max_SubArray(int Array[],int Size){
	struct ArrayNode *maxArray;
	int i,j,max=INT_MIN,sum,font,nail;
	maxArray = (struct ArrayNode*)malloc(sizeof(struct ArrayNode));
	for(i=1;i<=Size;i++){
		sum = 0;
		for(j=i;j<=Size;j++){
			sum += Array[j];
			if(sum>max){
				max=sum;
				font=i;
				nail=j;
			}
		}
	}
	maxArray->low = font;
	maxArray->high = nail;
	maxArray->maxsum = max;
	return maxArray;
}*/
//分治算法求解;
struct ArrayNode* Find_cross_SubArray(int Array[],int low,int high,int mid){
	int i,j;
	int left_max=INT_MIN,right_max=INT_MIN,font,nail;
	int left_sum=0,right_sum=0;
	struct ArrayNode *midArray;
	midArray = (struct ArrayNode*)malloc(sizeof(struct ArrayNode));
	for(i=mid;i>=low;i--){
		left_sum += Array[i];
		if(left_sum>left_max){
			left_max=left_sum;
			font=i;
		}
	}
	for(j=mid+1;j<=high;j++){
		right_sum += Array[j];
		if(right_sum>right_max){
			right_max=right_sum;
			nail=j;
		}
	}
	midArray->low = font;
	midArray->high = nail;
	midArray->maxsum = left_max+right_max;
	//printf("low:%d high:%d maxsum:%d\n",midArray->low,midArray->high,midArray->maxsum);
	return midArray;
}
struct ArrayNode* Find_max_SubArray(int Array[],int low,int high){
	struct ArrayNode *left_array,*right_array,*mid_array,*array;
	int mid;
	if(low==high){
		array = (struct ArrayNode*)malloc(sizeof(struct ArrayNode));
		array->low = array->high = low;
		array->maxsum = Array[low];
		//printf("low:%d high:%d maxsum:%d\n",array->low,array->high,array->maxsum);
		return array;
	}else{
		mid=(low+high)/2;
		left_array = Find_max_SubArray(Array,low,mid);
		right_array = Find_max_SubArray(Array,mid+1,high);
		mid_array = Find_cross_SubArray(Array,low,high,mid);
		if(left_array->maxsum>=right_array->maxsum && left_array->maxsum>=mid_array->maxsum){
		//printf("low:%d high:%d maxsum:%d\n",left_array->low,left_array->high,left_array->maxsum);
		return left_array;
		}
		else if(right_array->maxsum>=left_array->maxsum && right_array->maxsum>=mid_array->maxsum){
		//printf("low:%d high:%d maxsum:%d\n",right_array->low,right_array->high,right_array->maxsum);
		return right_array;
		}
		else{
		//printf("low:%d high:%d maxsum:%d\n",mid_array->low,mid_array->high,mid_array->maxsum);
		return mid_array;
		}
	}
}
int main(){
	int Array[] = {0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int Size = 16;
	struct ArrayNode *array1;
	array1=Find_max_SubArray(Array,1,Size);
	printf("low:%d high:%d maxsum:%d\n",array1->low,array1->high,array1->maxsum);
	return 0;
}
