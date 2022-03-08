using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloWorldApp
{

  static class Program
  {

    /// <summary>
    /// test
    /// </summary>
    static void Test()
    {
      ///
    }

    /// <summary>
    ///  The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
      Application.SetHighDpiMode(HighDpiMode.SystemAware);

<<<<<<< Updated upstream

=======
      // poprawka w brach_1
      // poprawka w brach_2
>>>>>>> Stashed changes

      Application.EnableVisualStyles();
      Application.SetCompatibleTextRenderingDefault(false);

      Test();

      Application.Run(new Form1());
    }
  }
}
