vim.g.base46_cache = vim.fn.stdpath "data" .. "/base46/"
vim.g.mapleader = " "

-- bootstrap lazy and all plugins
local lazypath = vim.fn.stdpath "data" .. "/lazy/lazy.nvim"

if not vim.uv.fs_stat(lazypath) then
  local repo = "https://github.com/folke/lazy.nvim.git"
  vim.fn.system { "git", "clone", "--filter=blob:none", repo, "--branch=stable", lazypath }
end

vim.opt.rtp:prepend(lazypath)

local lazy_config = require "configs.lazy"

-- load plugins
require("lazy").setup({
  {
    "NvChad/NvChad",
    lazy = false,
    branch = "v2.5",
    import = "nvchad.plugins",
  },
  {
    "folke/flash.nvim",
    event = "VeryLazy",
    ---@type Flash.Config
    opts = {
      highlight = {
        backdrop = true,
      },
      modes = {
        char = {
          highlight = {
            backdrop = true,
          },
        },
      },
    },
    -- stylua: ignore
    keys = {
      { "s", mode = { "n", "x", "o" }, function() require("flash").jump() end, desc = "Flash" }, { "S", mode = { "n", "x", "o" }, function() require("flash").treesitter() end, desc = "Flash Treesitter" },
      { "<esc>", mode = { "n", "x", "o" }, function()
        local char = require("flash.plugins.char")
        if char.state then
          char.state:hide()
        end
      end, desc = "Cancel Flash Char" },
      { "r", mode = "o", function() require("flash").remote() end, desc = "Remote Flash" },
      { "R", mode = { "o", "x" }, function() require("flash").treesitter_search() end, desc = "Treesitter Search" },
      { "<c-s>", mode = { "c" }, function() require("flash").toggle() end, desc = "Toggle Flash Search" },
    },
  },


  { import = "plugins" },
}, lazy_config)

vim.keymap.set({"n", "i"}, "<C-h>", function() print("hello") end)

-- load theme
dofile(vim.g.base46_cache .. "defaults")
dofile(vim.g.base46_cache .. "statusline")

require "options"
require "nvchad.autocmds"

vim.schedule(function()
  require "mappings"
end)

---[[
local vimrc = {
"set modelines=0",
"set number",
"set ruler",
"set encoding=utf-8",
"set wrap",
"set textwidth=79",
"set formatoptions=tcqrn1",
"set tabstop=2",
"set shiftwidth=2",
"set softtabstop=2",
"set expandtab",
"set noshiftround",
"set scrolloff=99999",
"set backspace=indent,eol,start",
"set hidden",
"set ttyfast",
"set laststatus=2",
"set showmode",
"set showcmd",
"set hlsearch",
"set incsearch",
"set ignorecase",
"set smartcase",
"set showmatch",
}
for _,v in ipairs(vimrc) do
  vim.cmd(v)
end
--]]
