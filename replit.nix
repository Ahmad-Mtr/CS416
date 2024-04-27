{ pkgs }: {
	deps = [
   pkgs.tree
   pkgs.neovim
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}