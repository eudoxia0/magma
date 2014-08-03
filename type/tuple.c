macro tup {
  case {
    match {
      ($(a), $(b))
    }
    template {
      struct { $(a) first; $(b) second; }
    }
  }
}
