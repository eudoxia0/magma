macro recur_name {
  case {
    match {
      ($(type-name) $(name) $(def block);)
    }
    template {
      $(@conc type-name name),
    }
  }
  case {
    match {
      ($(type-name) $(name) $(def block); $(others rest))
    }
    template {
      recur_name ($(type-name) $(name) $(def);)
      recur_name ($(type-name) $(others))
    }
  }
}

macro recur_def {
  case {
    match {
      ($(name) $(def block);)
    }
    template {
      struct $(name) $(def) $(name);
    }
  }
  case {
    match {
      ($(name) $(def block); $(others rest))
    }
    template {
      recur_def ($(name) $(def);) recur_def ($(others))
    }
  }
}

macro data {
 case {
   match {
     $(name) {
       $(definitions rest)
     }
   }
   template { /* Nothing */ }
   toplevel {
     typedef enum { recur_name ($(name) $(definitions)) }
       $(@gensym data);

     typedef struct {
       $(@getsym data) type;
       union {
         recur_def ($(definitions))
       };
     } $(name);
   }
  }
}

macro construct {
  case {
    match {
      ($(name), $(type) -> $(subtype)) $(assignments);
    }
    template {
      $(name) . type = $(@conc type subtype);
      $(name) . $(subtype) = (struct $(subtype))$(assignments);
    }
  }
}
