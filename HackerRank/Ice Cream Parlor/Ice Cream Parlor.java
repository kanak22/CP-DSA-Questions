import java.util.*;
public class iceCreamParlour {

	public static int search(int arr[],int c,int m) {

		for(int i=0; i<arr.length;i++) {
			if(arr[i]==c && i!=m) // We check if c is present in the array and make sure the cost of two ice-creams are in two different indices.
				return i;
		}
		return -1; // If an ice-cream worth c is not present, first friend cannot buy ice-cream of cost arr[i].
	}
	public static void main(String args[]) {
		Scanner sc= new Scanner(System.in);
		int T= sc.nextInt();
		for(int t=1; t<=T; t++) {
			int k= sc.nextInt();
			int n= sc.nextInt();
			int arr[]= new int[n];
			for(int i=0; i<n; i++)
				arr[i]= sc.nextInt();
			for(int i=0; i<n; i++) {
				int c= k-arr[i];  //c holds the price of the other ice-cream if the ice-cream worth arr[i] is bought.
				if(c>0) {
					int present= search(arr,c,i); // We search if c exists in the array. If it is present, one friend can have ice-cream worth arr[i] and other worth c.
					if(present!=-1) {
						String s;
						if(present>i)
							 s=(i+1)+" "+(present+1);
						else
							 s=(present+1)+" "+(i+1);
					System.out.println(s); // Print indices in ascending order.
					break;
					}

				}
			}
		}
		sc.close();
	}
}

