import java.util.Scanner;

public class Pangrams {

	public static String pangram(String s) {
		// Starting from first alphabet 'a', 'A' till last 'z','Z', we check if all are present in the string or not.
	    for(int i=1; i<=26; i++){  
	        char uc= (char)(i+64);  //lower case alphabets
	        char lc= (char)(i+96);  //upper case alphabets
	        if(s.indexOf(uc)==-1 && s.indexOf(lc)==-1)
	          return "not pangram";
	    }
	      return "pangram";
	    }

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
			String s= sc.nextLine();
			System.out.println(pangram(s));
		sc.close();
	}
}