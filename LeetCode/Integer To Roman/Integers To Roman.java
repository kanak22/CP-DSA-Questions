class Solution {
    public String intToRoman(int num) {
        //created a numbers array along with its respective roman value
        int[] no={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] code={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        StringBuilder sb=new StringBuilder();
        
        for(int i=0;i<no.length;i++)
        {
            //basic idea is to seperate the bigger value ie. 1000  than 500 .... so on to 1
            //and store their values in string
            while(num >= no[i])//for num 2300 
            {
                
                sb.append(code[i]);//M is appended
                num-=no[i];//2300-1000 = 1300
            }//continues until the number is greter
        }
        
        return sb.toString();
    }
}