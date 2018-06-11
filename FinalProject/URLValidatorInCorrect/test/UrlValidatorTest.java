

import junit.framework.TestCase;
import static org.junit.Assert.assertTrue;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }


   /*
   public void testManualTest()
   {
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("**Begin Manual Test**");

	   System.out.urlVal.isValid("http://www.amazon.com"));
     //System.out.urlVal.isValid("ftp://go.au")); //error
     //System.out.urlVal.isValid("ftp://go.au:80")); //error
     System.out.println(urlVal.isValid("httpg://www.amazon.com")); //does not assert to False
	   //System.out.println(urlVal.isValid("http://300.55.33.257"));
	   System.out.println(urlVal.isValid("html://www.amazon.89"));
     System.out.println("**End Manual Test**");

   }
  */


   public void testYourFirstPartition()
   {
  	 //You can use this function to implement your First Partition testing
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

     System.out.println("First Partition....");
     //Partition by scheme

      System.out.println("[===============First batch: scheme:============]");
      System.out.println(urlVal.isValid("http://www.amazon.com")); //valid
      System.out.println(urlVal.isValid("ftp://www.amazon.com")); //valid
      System.out.println(urlVal.isValid("h3t://www.amazon.com")); //valid
      System.out.println(urlVal.isValid("abc//www.amazon.com")); //not valid
      System.out.println(urlVal.isValid("3ht//www.amazon.com"));  //not valid
      System.out.println(urlVal.isValid("://www.amazon.com")); //not valid
      System.out.println(urlVal.isValid("http/www.amazon.com")); //not valid
      System.out.println(urlVal.isValid("amazon.com")); // not valid

   }

   public void testYourSecondPartition(){
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      System.out.println("Second Partition....");

    	 System.out.println("[===============Second batch: //host============]");
  	   System.out.println(urlVal.isValid("http://www.amazon.com"));
       System.out.println(urlVal.isValid("http://www.amazon.au"));
       System.out.println(urlVal.isValid("http://www.amazon.cc"));
       System.out.println(urlVal.isValid("http://www.amazon.com:80")); //should be valid
       System.out.println(urlVal.isValid("http://www.amazon.com:abc")); //should be false
  	   System.out.println(urlVal.isValid("http://www.amazon.")); //should be FALSE but is not.

   }

   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }


}
