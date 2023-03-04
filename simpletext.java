import java.awt.*;
import javax.swing.*;
import java.io.*;
import java.awt.event.*;


class SimpleText extends JFrame {
    private JPanel p1, p2;
    private JTextArea EditorArea;
    private String fileName = "";

    private TextField textName;


    SimpleText() {
        super("简单文本编辑器");

        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
        } catch (Exception e) {
            System.out.println("Look and Feel Exception");
            System.exit(0);
        }


        JMenuBar bar = new JMenuBar();

        JMenu menuFile = new JMenu("文件");
        JMenu menuEdit = new JMenu("编辑");

        JMenuItem FileOpen = new JMenuItem("打开");
        JMenuItem FileOpens = new JMenuItem("打开...");
        JMenuItem FileKeep = new JMenuItem("保存");
        JMenuItem FileSave = new JMenuItem("另存为");
        JMenuItem exit = new JMenuItem("退出");

        JMenuItem Cut=new JMenuItem("剪切");
        JMenuItem Copy=new JMenuItem("复制");
        JMenuItem Paste=new JMenuItem("粘贴");


        menuFile.add(FileOpen);
        menuFile.add(FileOpens);
        menuFile.add(FileKeep);
        menuFile.add(FileSave);
        menuFile.addSeparator();
        menuFile.add(exit);

        menuEdit.add(Cut);
        menuEdit.add(Copy);
        menuEdit.add(Paste);

        bar.add(menuFile);
        bar.add(menuEdit);


        setJMenuBar(bar);




        p1 = new JPanel(new FlowLayout(FlowLayout.CENTER));
        p2 = new JPanel(new FlowLayout(FlowLayout.CENTER));


        JLabel lblName = new JLabel("文本文件的路径、名称:");
        textName = new TextField(46);

        p1.add(lblName);
        p1.add(textName);
        this.add(p1, BorderLayout.NORTH);


        EditorArea = new JTextArea();


        EditorArea.setFont(new Font("宋体", Font.PLAIN, 20));
        EditorArea.setLineWrap(true);


        this.add(EditorArea);

        this.add(EditorArea, BorderLayout.CENTER);


        JButton open = new JButton("打开文件");


        JButton opens = new JButton("打开文件...");


        JButton keep = new JButton("保存文件");
        JButton save = new JButton("另存为...");

        JButton reset = new JButton("重置");

        p2.add(open);
        p2.add(opens);
        p2.add(new JLabel(""));
        p2.add(keep);
        p2.add(save);
        p2.add(new JLabel(""));
        p2.add(reset);


        this.add(p2, BorderLayout.SOUTH);


        this.setSize(900, 600);
        this.setLocation(400, 200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.setVisible(true);


        FileOpen.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                openFile();
            }
        });


        FileOpens.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JFileChooser fc = new JFileChooser();

                int rVal = fc.showOpenDialog(SimpleText.this);

                if (rVal == JFileChooser.APPROVE_OPTION) {

                    fileName = fc.getSelectedFile().getName();

                    String path = fc.getCurrentDirectory().toString();
                    try {

                        FileReader fr = new FileReader(path + "/" + fileName);

                        BufferedReader br = new BufferedReader(fr);

                        String line = br.readLine();

                        while (line != null) {
                            EditorArea.append(line + "\n");

                            line = br.readLine();
                        }
                        br.close();
                        fr.close();
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                }
            }

        });


        FileKeep.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                writeFile();
            }
        });


        FileSave.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JFileChooser fc = new JFileChooser();

                int rVal = fc.showSaveDialog(SimpleText.this);

                if (rVal == JFileChooser.APPROVE_OPTION) {

                    fileName = fc.getSelectedFile().getName();

                    String path = fc.getCurrentDirectory().toString();


                    try {

                        FileWriter fw = new FileWriter(path + "/" + fileName);

                        fw.write(EditorArea.getText());
                        fw.close();
                    } catch (Exception e1) {
                        e1.printStackTrace();
                    }
                }

            }
        });


        exit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        Cut.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                EditorArea.cut();
            }
        });

        Copy.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                EditorArea.copy();
            }
        });

        Paste.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                EditorArea.paste();
            }
        });





        open.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                openFile();
            }
        });


        opens.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JFileChooser fc = new JFileChooser();

                int rVal = fc.showOpenDialog(SimpleText.this);

                if (rVal == JFileChooser.APPROVE_OPTION) {

                    fileName = fc.getSelectedFile().getName();

                    String path = fc.getCurrentDirectory().toString();
                    try {

                        FileReader fr = new FileReader(path + "/" + fileName);

                        BufferedReader br = new BufferedReader(fr);

                        String line = br.readLine();

                        while (line != null) {
                            EditorArea.append(line + "\n");

                            line = br.readLine();
                        }
                        br.close();
                        fr.close();
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                }
            }
        });


        keep.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                writeFile();
            }
        });


        save.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {


                JFileChooser fc = new JFileChooser();

                int rVal = fc.showSaveDialog(SimpleText.this);

                if (rVal == JFileChooser.APPROVE_OPTION) {

                    fileName = fc.getSelectedFile().getName();

                    String path = fc.getCurrentDirectory().toString();


                    try {

                        FileWriter fw = new FileWriter(path + "/" + fileName);

                        fw.write(EditorArea.getText());
                        fw.close();
                    } catch (Exception e1) {
                        e1.printStackTrace();
                    }
                }

            }
        });


        reset.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                EditorArea.setText("");
            }
        });

    }


    private void openFile() {

        if ((textName.getText().length()) > 0) {
            try {

                FileReader fr = new FileReader(textName.getText());

                BufferedReader br = new BufferedReader(fr);

                String line = br.readLine();

                while (line != null) {
                    EditorArea.append(line + "\n");

                    line = br.readLine();
                }


                JOptionPane.showMessageDialog(null, "文件已打开！");
                br.close();
                fr.close();
            } catch (Exception e) {
                e.printStackTrace();
            }


        } else {
            JOptionPane.showMessageDialog(null, "文件名不能为空，" + '\n' + "请输入或选择后再操作！");
        }


    }


    private void writeFile() {


        try {

            FileWriter fw = new FileWriter(textName.getText());

            fw.write(EditorArea.getText());
            fw.close();
            JOptionPane.showMessageDialog(null, "文件保存完毕！");
        } catch (Exception e) {
            e.printStackTrace();
        }


    }


    public static void main(String[] args) {
        new SimpleText();
    }
}
