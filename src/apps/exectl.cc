/* exectl.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 */

#include <gflags/gflags.h>
#include <libtecla.h>

#include <iostream>
#include <iterator>
#include <thread>
#include <chrono>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <cstring>
#include <atomic>

#include <stdio.h>
#include <stdlib.h>

  static std::atomic<bool> is_running(true);

  static void interrupt(int signo)
  {
    switch(signo)
    {
      case SIGINT:
        is_running = false;
        break;
      default:
        std::cerr << "unhandled signal" << std::endl << std::flush;
    }
  }
  
  DEFINE_bool(debug,   false, "debug");
  DEFINE_bool(verbose, false, "verbose");

  int main(int argc, char *argv[])
  {
    int status = EXIT_SUCCESS;

    std::string usage("Execution Control.  Sample usage:\n");
    usage += argv[0];
    usage += " ";
    gflags::SetUsageMessage(usage);
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    PathCache *pc = new_PathCache();
    if(!pc) exit(1);
    if(pca_scan_path(pc, getenv("PATH"))) {
      fprintf(stderr, "%s\n", pca_last_error(pc));
      exit(1);
    }
    pca_set_check_fn(pc, cpl_check_exe, NULL);
    for(int i=1; i<argc; i++) {
      char *cmd = pca_lookup_file(pc, argv[i], -1, 0);
      printf("The full pathname of '%s' is %s\n", argv[i],
      cmd ? cmd : "unknown");
    }
    pc = del_PathCache(pc);

    return status;
  }


/* *EOF* */
