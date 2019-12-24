class Template implements Runnable{
    public void solve(){}
    InputReader in;PrintWriter out;
    @Override
    public void run() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        try {
            if (System.getProperty("user.name").equals("puneet")) {
                outputStream = new FileOutputStream("path/output.txt");
                inputStream = new FileInputStream("path/input.txt");
            }
        } catch (Exception ignored) {}
        out = new PrintWriter(outputStream);
        in = new InputReader(inputStream);
        solve();
        out.flush();}

    public static void main(String[] args) {
        new Thread(null,new Template(),"Main",1<<27).start();
    }
    class InputReader {
        InputStream obj;
        public InputReader(InputStream obj) {
            this.obj = obj;
        }
        byte inbuffer[] = new byte[1024];
        int lenbuffer = 0, ptrbuffer = 0;

        int readByte() {
            if (lenbuffer == -1) throw new InputMismatchException();
            if (ptrbuffer >= lenbuffer) {
                ptrbuffer = 0;
                try {
                    lenbuffer = obj.read(inbuffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            if (lenbuffer <= 0) return -1;
            return inbuffer[ptrbuffer++];
        }
        String ns() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) // when nextLine, (isSpaceChar(b) && b!=' ')
            {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        int ni() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }
        long nl() {
            long num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10L + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }
        boolean isSpaceChar(int c) {
            return (!(c >= 33 && c <= 126));
        }
        int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }
        float nf() {return Float.parseFloat(ns());}
        double nd() {return Double.parseDouble(ns());}
        char nc() {return (char) skip();}}}