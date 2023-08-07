 class ExceptionDemo {

              public static void main(String args[])  {

                        try {

                                int n1 = Integer.parseInt(args[0]);

                                int n2 = Integer.parseInt(args[1]);

                                int sum=n1+n2;

                                System.out.println("\n Sum=" + sum);

                         } catch (NumberFormatException e) {

                                  System.out.println(e);

                            }

                            finally {

                                      System.out.println("You inputted a correct integer number");

                            }

                      }

               }