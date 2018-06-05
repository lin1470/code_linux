import java.security.*;
import javax.crypto.*;
import javax.crypto.spec.*;
import java.io.*;

/**
 *	This class encrypts and decrypts a file using CipherStreams
 *	and a 256-bit Rijndael key stored in the filesystem.
 */

public class FileEncryptor
{
  private static String KEY_FILENAME="rijndaelkey.bin";
  private static int ITERATIONS=1000;

  public static void main (String[] args)
  throws Exception
  {
    // 检查命令的参数的个数.args[0]是参数，args[1]是口令，args[3]是InputFile,args[4]是ouputFile
    if ((args.length < 2) || (args.length > 4))
    {
      System.err.println("Usage: java CipherStreamExample -c|-e|-d password [inputfile] [outputfile]");
      System.exit(1);
    }

    // 注意了这个password指的是口令。是我们用户自己设置的。
    // 把口令转换为一个字符串数组利于后面的数据的处理
    char[] password = new char[args[1].length()];
    args[1].getChars(0, args[1].length(), password, 0);
    // 如果参数是-c的话，那么就是生成口令。
    // 如果参数是-e的话，那么就是加密。
    // 如果参数是-d的话，那么就是解密。
    if ("-c".equals(args[0])) createKey(password);
    else if ("-e".equals(args[0])) encrypt(password, args[2], args[3]);
    else if ("-d".equals(args[0])) decrypt(password, args[2], args[3]);
  }

  /**
   *	Creates a 256-bit Rijndael key and stores it to
   *	the filesystem as a KeyStore.
   */
  private static void createKey(char[] password)
  throws Exception
  {
    System.out.println("Generating a Rijndael key...");

    // 生成一个 Rijndael算法的密钥
    KeyGenerator keyGenerator = KeyGenerator.getInstance("Rijndael");
    keyGenerator.init(128); // 初始化为128位的。
    Key key = keyGenerator.generateKey();

    System.out.println("Done generating the key.");

    // Now we need to create the file with the key,
    // encrypting it with a password.
    byte[] salt = new byte[8]; // 生成一个8字节的盐
    SecureRandom random = new SecureRandom();
    random.nextBytes(salt); // 随机生成一个盐。
    PBEKeySpec pbeKeySpec = new PBEKeySpec(password); // 创建一个基于口令的的密钥
    SecretKeyFactory keyFactory = SecretKeyFactory.getInstance(
		"PBEWithSHAAndTwofish-CBC");
    SecretKey pbeKey = keyFactory.generateSecret(pbeKeySpec); // 创建一个pbe的带口令的密钥
    PBEParameterSpec pbeParamSpec = new PBEParameterSpec(salt, ITERATIONS);
    Cipher cipher = Cipher.getInstance("PBEWithSHAAndTwofish-CBC");
    cipher.init(Cipher.ENCRYPT_MODE, pbeKey, pbeParamSpec);

    // 加密带口令的密钥
    byte[] encryptedKeyBytes = cipher.doFinal(key.getEncoded());

    // 然后把盐和带口令的加密密钥写进rijndaelkey.bin这个文件里面的。
    FileOutputStream fos = new FileOutputStream(KEY_FILENAME);
    fos.write(salt);
    fos.write(encryptedKeyBytes);
    fos.close();

  }

  /**
   *	Loads a key from the filesystem
   */
  private static Key loadKey(char[] password)
  throws Exception
  {
	// Load the bytes from the encrypted key file.
    FileInputStream fis = new FileInputStream(KEY_FILENAME);
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    int i = 0;
    while ((i=fis.read()) != -1) {
		baos.write(i);
	}
	fis.close();
	byte[] saltAndKeyBytes = baos.toByteArray();
	baos.close();

	// 获取从文件中获取盐，是前面的八个字节
	byte[] salt = new byte[8];
	System.arraycopy(saltAndKeyBytes,0,salt,0,8);

	// 获取加密后的密钥的字节
	int length = saltAndKeyBytes.length - 8;
	byte[] encryptedKeyBytes = new byte[length];
	System.arraycopy(saltAndKeyBytes,8,encryptedKeyBytes,0,length);

	// 生成一个PBE的解密器，带口令的。
    PBEKeySpec pbeKeySpec = new PBEKeySpec(password);
    SecretKeyFactory keyFactory = SecretKeyFactory.getInstance(
		"PBEWithSHAAndTwofish-CBC");
	SecretKey pbeKey = keyFactory.generateSecret(pbeKeySpec);
	PBEParameterSpec pbeParamSpec = new PBEParameterSpec(salt, ITERATIONS);// 重复计算1000次盐然后输出。
	Cipher cipher = Cipher.getInstance("PBEWithSHAAndTwofish-CBC");
	cipher.init(Cipher.DECRYPT_MODE, pbeKey, pbeParamSpec);

	// 把密钥解出来
	byte[] decryptedKeyBytes = cipher.doFinal(encryptedKeyBytes);

	// 获得完整的一个key,然后将其返回。
	SecretKeySpec key = new SecretKeySpec(decryptedKeyBytes, "Rijndael");
	return key;

  }

  /**
   *	Encrypt a file using Rijndael. Load the key
   *	from the filesystem, given a password.
   */
  private static void encrypt(char[] password, String fileInput, String fileOutput)
  throws Exception
  {
    // 从文件中读取一个key
    System.out.println("Loading the key.");
    Key key = loadKey(password);
    System.out.println("Loaded the key.");

    // 创建一个加密器，用key来加密
    Cipher cipher = Cipher.getInstance("Rijndael/CBC/PKCS5Padding");

    System.out.println("Initializing SecureRandom...");
    // 初始化16个字节的块
    // Now we need an Initialization Vector for the cipher in CBC mode.
	// We use 16 bytes, because the block size of Rijndael is 256 bits.
    SecureRandom random = new SecureRandom();
    byte[] iv = new byte[16];
    random.nextBytes(iv);

    FileInputStream fis = new FileInputStream(fileInput);
    FileOutputStream fos = new FileOutputStream(fileOutput);

	  // 先把第一个iv写到文件里面。
    fos.write(iv);
    IvParameterSpec spec = new IvParameterSpec(iv);

    System.out.println("Initializing the cipher.");
    // 初始化一个加密器 
    cipher.init(Cipher.ENCRYPT_MODE, key, spec);
    // 创建一个加密器输出流。
    CipherOutputStream cos = new CipherOutputStream(fos, cipher);

    System.out.println("Encrypting the file...");
    // 把所有的读入都加密了然后输出。
    int theByte = 0;
    while ((theByte = fis.read()) != -1)
    {
      cos.write(theByte);
    }
    fis.close();
    cos.close();
  }

  /**
   *	Decrypt a file using Rijndael. Load the key
   *	from the filesystem, given a password.
   */
  private static void decrypt(char[] password, String fileInput, String fileOutput)
          throws Exception
  {
    // 完全就是加密的你过程。
    System.out.println("Loading the key.");
    Key key = loadKey(password);
    System.out.println("Loaded the key.");

    // Create a cipher using that key to initialize it
    Cipher cipher = Cipher.getInstance("Rijndael/CBC/PKCS5Padding");

    FileInputStream fis = new FileInputStream(fileInput);
    FileOutputStream fos = new FileOutputStream(fileOutput);

    // Read the IV from the file. It's the first 16 bytes.
    byte[] iv = new byte[16];
    fis.read(iv);

    IvParameterSpec spec = new IvParameterSpec(iv);

    System.out.println("Initializing the cipher.");
    cipher.init(Cipher.DECRYPT_MODE, key, spec);

    CipherInputStream cis = new CipherInputStream(fis, cipher);

    System.out.println("Decrypting the file...");

    int theByte = 0;
    while ((theByte = cis.read()) != -1)
    {
      fos.write(theByte);
    }
    cis.close();
    fos.close();
  }
}