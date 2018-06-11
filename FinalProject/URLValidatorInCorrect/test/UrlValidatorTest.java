

import junit.framework.TestCase;
import static org.junit.Assert.assertTrue;
import java.util.HashMap;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }



   public void testManualTest()
   {
     //You can use this function to implement your manual testing
            long allowAllSchemes = UrlValidator.ALLOW_ALL_SCHEMES;
            UrlValidator urlValidator2 = new UrlValidator(null, null, allowAllSchemes);
            System.out.println("[====Manual Testing Begin====]");
            //Valid URLS
            System.out.println("Valid Manual Tests");
            if (urlValidator2.isValid("http://www.yahoo.com")) {
                System.out.println("url1 is valid - correct");
            } else {
                System.out.println("url1 is invalid - FAILED");
            }
            if (urlValidator2.isValid("https://www.amazon.com/")) {
                System.out.println("url2 is valid - correct");
            } else {
                System.out.println("url2 is invalid - FAILED");
            }
            if (urlValidator2.isValid("https://www.australia.gov.au/")) {
                System.out.println("url3 is valid - correct");
            } else {
                System.out.println("url3 is invalid - FAILED");
            }
            if (urlValidator2.isValid("http://google.com/")) {
                System.out.println("url4 is valid - correct");
            } else {
                System.out.println("url4 is invalid - FAILED");
            }
            if (urlValidator2.isValid("https://docs.google.com/document/d/1Ui-sTfm_f52wv2K5p8Ja1axxYya8A4Tz5hUwCnlI74c/edit")) {
                System.out.println("url5 is valid - correct");
            } else {
                System.out.println("url5 is invalid - FAILED");
            }
            if (urlValidator2.isValid("http://flip3.engr.oregonstate.edu:16943")) {
                System.out.println("url6 is valid - correct");
            } else {
                System.out.println("url6 is invalid - FAILED");
            }
            //Invalid URLS
            System.out.println("Invalid Manual Tests");
            if (urlValidator2.isValid("https://docs.google.com///1Ui-sTfm_f52wv2K5p8Ja1axxYya8A4Tz5hUwCnlI74c/edit")) {
                System.out.println("url7 is valid - FAILED");
            } else {
                System.out.println("url7 is invalid - correct");
            }
            if (urlValidator2.isValid("3ht://www.google.com")) {
                System.out.println("url8 is valid - FAILED");
            } else {
                System.out.println("url8 is invalid - correct");
            }
            if (urlValidator2.isValid("http://www.yahoo.com/#")) {
                System.out.println("url9 is valid - FAILED");
            } else {
                System.out.println("url9 is invalid - correct");
            }
            if (urlValidator2.isValid("http://aaa")) {
                System.out.println("url10 is valid - FAILED");
            } else {
                System.out.println("url10 is invalid - correct");
            }
            if (urlValidator2.isValid("http://www.go.com:-1")) {
                System.out.println("url11 is valid - FAILED");
            } else {
                System.out.println("url11 is invalid - correct");
            }
            if (urlValidator2.isValid("http:/google.com")) {
                System.out.println("url12 is valid - FAILED");
            } else {
                System.out.println("url12 is invalid - correct");
            }

            //Boundary URLs
            System.out.println("Boundary Manual Tests");
            if (urlValidator2.isValid("h3t://google.com")) {
                System.out.println("url13 is valid - correct");
            } else {
                System.out.println("url13 is invalid - FAILED");
            }
            if (urlValidator2.isValid("http://www.google.com:0")) {
                System.out.println("url14 is valid - correct");
            } else {
                System.out.println("url14 is invalid - FAILED");
            }
            if (urlValidator2.isValid("http://google.ca")) {
                System.out.println("url15 is valid - correct");
            } else {
                System.out.println("url15 is invalid - FAILED");
            }
            if (urlValidator2.isValid("google.com")) {
                System.out.println("url16 is valid - correct");
            } else {
                System.out.println("url16 is invalid - FAILED");
            }
            if (urlValidator2.isValid("http://")) {
                System.out.println("url17 is valid - correct");
            } else {
                System.out.println("url17 is invalid - FAILED");
            }
            if (urlValidator2.isValid("http:/google.com/file1/")) {
                System.out.println("url18 is valid - correct");
            } else {
                System.out.println("url18 is invalid - FAILED");
            }
            System.out.println("[====Manual Testing End====]");
   }



   public void testYourFirstPartition()
   {
  	 //You can use this function to implement your First Partition testing
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

     System.out.println("[=====First Partition Begins====]");
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

      System.out.println("Second Partition Begins");

    	 System.out.println("[===============Second batch: //host============]");
  	   System.out.println(urlVal.isValid("http://www.amazon.com"));
       System.out.println(urlVal.isValid("http://www.amazon.au"));
       System.out.println(urlVal.isValid("http://www.amazon.cc"));
       System.out.println(urlVal.isValid("http://www.amazon.com:80")); //should be valid
       System.out.println(urlVal.isValid("http://www.amazon.com:abc")); //should be false
  	   System.out.println(urlVal.isValid("http://www.amazon.")); //should be FALSE but is not.
       System.out.println("Second Partition Ends");

   }
   public static void updateMap(HashMap<String, Integer> update, String checkString) {
   		int count = update.containsKey(checkString) ? update.get(checkString) : 0;
   		update.put(checkString, count + 1);
   	}
   	public static void testIsValid()
   	{

      System.out.println("[==== programming based testing ====]");


   		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

   		ResultPair[] scheme = {new ResultPair("http://", true), new ResultPair("ftp://", true), new ResultPair("3ht://", false)};
   		ResultPair [] authority = {new ResultPair("www.google.com", true), new ResultPair("go.com", true), new ResultPair("go.ala", false)};
   		ResultPair [] port = {new ResultPair(":80", true), new ResultPair("", true), new ResultPair(":-2", false)};
   		ResultPair [] path = {new ResultPair("/something", true), new ResultPair("", true), new ResultPair("///", false)};
   		ResultPair [] query = {new ResultPair("", true), new ResultPair("?action=view", true), new ResultPair("#//garbage//", false)};

   		// Hashmaps count instances where an URL is false when it should have been true. The highest count values are the common elements and
   		// are likely to be causing the failures.
   		HashMap<String, Integer> schemeFalseFail = new HashMap<>();
   		HashMap<String, Integer> authorityFalseFail = new HashMap<>();
   		HashMap<String, Integer> portFalseFail = new HashMap<>();
   		HashMap<String, Integer> pathFalseFail = new HashMap<>();
   		HashMap<String, Integer> queryFalseFail = new HashMap<>();
   		for (int sch = 0; sch < 3; sch ++) {
   			System.out.println("Testing scheme: " + scheme[sch].item);
   			for (int auth = 0; auth < 3; auth ++) {

   				for (int por = 0; por < 3; por ++) {

   					for (int pat = 0; pat < 3; pat ++) {

   						for (int que = 0; que < 3; que ++) {

   							String urlTest = scheme[sch].item + authority[auth].item  + port[por].item  + path[pat].item  + query[que].item ;
   							boolean got = urlVal.isValid(urlTest);
   							boolean expected = scheme[sch].valid & authority[auth].valid  & port[por].valid  & path[pat].valid  & query[que].valid;
   							//assertTrue(got == expected); // crashes
   							if(got != expected) {
   								System.out.println("Expected: " + expected + " Got: " + got);
   								System.out.println("URL " + urlTest);
   								if (expected == false) {
   									System.out.println("-- False VALID");


   									System.out.println("False parts: ");
   									if (!scheme[sch].valid) System.out.println("Scheme: " + scheme[sch].item);
   									if (!authority[auth].valid) {
   										System.out.println("Authority: " + authority[auth].item);
   										//									authorityFailureWhenFalse[auth] += 1;
   									}
   									if (!port[por].valid) System.out.println("Port: " + port[por].item);
   									if (!path[pat].valid) System.out.println("Path: " + path[pat].item);
   									if (!query[que].valid) System.out.println("Query: " + query[que].item);
   									System.out.println();
   								} else if (expected == true) {
   									System.out.println("--FALSE FAILURE");
   									System.out.println();
   									updateMap(schemeFalseFail, scheme[sch].item);
   									updateMap(authorityFalseFail, authority[auth].item);
   									updateMap(portFalseFail, port[por].item);
   									updateMap(pathFalseFail, path[pat].item);
   									updateMap(queryFalseFail, query[que].item);
   								}
   							}
   						}
   					}
   				}
   			}
   			System.out.println("Counts for false failures:");
   			schemeFalseFail.forEach((k,v)->System.out.println("Count: " + v + "\tScheme " + k));
   			authorityFalseFail.forEach((k,v)->System.out.println("Count: " + v + "\tAuthority " + k));
   			portFalseFail.forEach((k,v)->System.out.println("Count: " + v + "\tPort " + k));
   			pathFalseFail.forEach((k,v)->System.out.println("Count: " + v + "\tPath " + k));
   			queryFalseFail.forEach((k,v)->System.out.println("Count: " + v + "\tQuery " + k));
   		}
      System.out.println("[==== programming based testing end ====]");

   	}

   	public static void main(String[] args) {

   		testIsValid();
   	}

   }
