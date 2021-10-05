import java.util.*;
public class findDigits {


	public static int Digits(int n) {

		int m=n, count=0;
		while(n>0){
			int p=n%10;                                   //Takes the last digit out of the number.
			if(p!=0 && m%p==0)                            //Checking if the digit completely divides the number. Division by 0 is not allowed.
				count++;  
			n/=10;          
		}
		return count;                                     //Returns the number of digits that divide the number.
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int T= sc.nextInt(); 
		for(int t=1; t<=T; t++) {
			int n= sc.nextInt();
			System.out.println(Digits(n));
		}
		sc.close();
	}
}
