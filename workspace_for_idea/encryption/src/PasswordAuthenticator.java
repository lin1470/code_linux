import java.security.*;
import java.io.*;
import java.util.*;

/**
 *	PasswordAuthenticator
 *
 *	This class creates and authenticates passwords.
 *
 *	A password is stored hashed in the file "password". It can
 *	then be validated with the command-line switch "-a".
 */
public class PasswordAuthenticator {

  /**
   *	两种运行方式:
   *
   *	-c password		生成一个口令.
   *	-a password		验证一个口令
   */
  public static void main (String[] args)
  throws Exception {

    if (args.length != 2) {
      System.err.println("Usage: java PasswordAuthenticator -c|-a password");
      System.exit(1);
    }

    if ("-c".equals(args[0])) {
      createPassword(args[1]);
    } else {
      authenticatePassword(args[1]);
    }
  }

  /**
   *	Create a hashed password and store it to the filesystem
   *	in a file named "password".
   *    创建一个哈希函数加密的口令，然后把它存进password名字的文件里面
   *    在口令中加入12字节的盐然后用MD5算法计算杂凑值。然后再以明文的形式存放该盐值和摘要结果，
   *    以便我们再以后的进程中进行验证。
   */
  private static void createPassword(String password)
  throws Exception {

    // Create a new salt
    SecureRandom random = new SecureRandom();
    byte[] salt = new byte[12];
    random.nextBytes(salt);

    // 获取一个带盐的口令的摘要
    MessageDigest md = MessageDigest.getInstance("MD5");
    md.update(salt);
    md.update(password.getBytes("UTF8"));
    byte[] digest = md.digest();

    // 打开password文件，把盐和口令摘要的杂凑值写进去。
    FileOutputStream fos = new FileOutputStream("password");
    fos.write(salt);
    fos.write(digest);
    fos.close();
  }

  /**
   *	用存储的口令来验证用户输入的口令。
   */
  private static void authenticatePassword(String password)
  throws Exception {

    // 从口令文件中读取一个字节数组。
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    FileInputStream fis = new FileInputStream("password");
    int theByte = 0;
    while ((theByte = fis.read()) != -1)
    {
      baos.write(theByte);
    }
    fis.close();
    byte[] hashedPasswordWithSalt = baos.toByteArray();
    baos.reset();
    // 盐在数组的前12个字节，因此我们将它们拷贝进一个新的数组
    byte[] salt = new byte[12];
    System.arraycopy(hashedPasswordWithSalt,0,salt,0,12);

    // 有了盐值，就可以对它和用户输入的口令计算杂凑值。
    MessageDigest md = MessageDigest.getInstance("MD5");
    md.update(salt);
    md.update(password.getBytes("UTF8"));
    byte[] digest = md.digest();

	// 现在与文件中存放的内容进行比较，即简单地读余下的内容。
    byte[] digestInFile = new byte[hashedPasswordWithSalt.length-12];
    System.arraycopy(hashedPasswordWithSalt,12,
    digestInFile,0,hashedPasswordWithSalt.length-12);

    // 现在我们有了两个摘要，一个来自文件，一个来自用户输入。我们对其进行比较。

    if (Arrays.equals(digest, digestInFile)) {
      System.out.println("Password matches.");
    } else {
      System.out.println("Password does not match");
    }
  }
}
