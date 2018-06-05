import java.security.MessageDigest;
import java.io.*;
import sun.misc.*;

/**
 *	DigestFile
 *
 *	This class creates an MD5 message digest from a file
 *	and displays it to the screen BASE64 Encoded.
 */
public class DigestFile {

  /**
   *	The only argument is the name of the file to be digested.
   */
  public static void main (String[] args) throws Exception {

    long startTime = System.currentTimeMillis();    //获取开始时间
    if (args.length != 1) {
      System.err.println("Usage: java DigestFile filename");
      System.exit(1);
    }

    // Create a message digest
    MessageDigest md = MessageDigest.getInstance("MD5");

    BufferedInputStream in = new BufferedInputStream(new FileInputStream(args[0]));

    int theByte = 0;
    while ((theByte = in.read()) != -1)
    {
      md.update((byte)theByte);
    }
    in.close();

    byte[] theDigest = md.digest();

    System.out.println(new BASE64Encoder().encode(theDigest));
    long endTime = System.currentTimeMillis();    //获取结束时间
    System.out.println("程序运行时间：" + (endTime - startTime) + "ms");    //输出程序运行时间
  }
}

