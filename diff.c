#include "graph.h"
static int diff_indent_heuristic; /* experimental */
static unsigned ws_error_highlight_default = WSEH_NEW;
static NORETURN void die_want_option(const char *option_name)
{
	die(_("option '%s' requires a value"), option_name);
}

		options->submodule_format = DIFF_SUBMODULE_LOG;
		options->submodule_format = DIFF_SUBMODULE_SHORT;
	else if (!strcmp(value, "diff"))
		options->submodule_format = DIFF_SUBMODULE_INLINE_DIFF;
static int parse_one_token(const char **arg, const char *token)
{
	const char *rest;
	if (skip_prefix(*arg, token, &rest) && (!*rest || *rest == ',')) {
		*arg = rest;
		return 1;
	}
	return 0;
}

static int parse_ws_error_highlight(const char *arg)
{
	const char *orig_arg = arg;
	unsigned val = 0;

	while (*arg) {
		if (parse_one_token(&arg, "none"))
			val = 0;
		else if (parse_one_token(&arg, "default"))
			val = WSEH_NEW;
		else if (parse_one_token(&arg, "all"))
			val = WSEH_NEW | WSEH_OLD | WSEH_CONTEXT;
		else if (parse_one_token(&arg, "new"))
			val |= WSEH_NEW;
		else if (parse_one_token(&arg, "old"))
			val |= WSEH_OLD;
		else if (parse_one_token(&arg, "context"))
			val |= WSEH_CONTEXT;
		else {
			return -1 - (int)(arg - orig_arg);
		}
		if (*arg)
			arg++;
	}
	return val;
}

int git_diff_heuristic_config(const char *var, const char *value, void *cb)
{
	if (!strcmp(var, "diff.indentheuristic")) {
		diff_indent_heuristic = git_config_bool(var, value);
		if (diff_indent_heuristic)
			diff_compaction_heuristic = 0;
	}
	if (!strcmp(var, "diff.compactionheuristic")) {
		diff_compaction_heuristic = git_config_bool(var, value);
		if (diff_compaction_heuristic)
			diff_indent_heuristic = 0;
	}
	return 0;
}

	if (git_diff_heuristic_config(var, value, cb) < 0)
		return -1;

	if (!strcmp(var, "diff.wserrorhighlight")) {
		int val = parse_ws_error_highlight(value);
		if (val < 0)
			return -1;
		ws_error_highlight_default = val;
		return 0;
	}

		if (!regexec_buf(word_regex, buffer->ptr + *begin,
				 buffer->size - *begin, 1, match, 0)) {
	o->found_changes = 1;

		fprintf(o->file, "%s", ecbdata->header->buf);
		fprintf(o->file, "%s%s--- %s%s%s\n",
		fprintf(o->file, "%s%s+++ %s%s%s\n",
			putc('\n', o->file);
			emit_line(o, context, reset, line, len);
			fputs("~\n", o->file);
			emit_line(o, context, reset, line, len);
		emit_line(o, diff_get_color(ecbdata->color_diff, DIFF_CONTEXT),
		width = term_columns() - strlen(line_prefix);
		if (p->one->oid_valid && p->two->oid_valid)
			content_changed = oidcmp(&p->one->oid, &p->two->oid);
	QSORT(dir.files, dir.nr, dirstat_compare);
	QSORT(dir.files, dir.nr, dirstat_compare);
	diff_set_mnemonic_prefix(o, "a/", "b/");
	if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}

	if (o->submodule_format == DIFF_SUBMODULE_LOG &&
	    (!one->mode || S_ISGITLINK(one->mode)) &&
	    (!two->mode || S_ISGITLINK(two->mode))) {
				&one->oid, &two->oid,
				two->dirty_submodule,
	} else if (o->submodule_format == DIFF_SUBMODULE_INLINE_DIFF &&
		   (!one->mode || S_ISGITLINK(one->mode)) &&
		   (!two->mode || S_ISGITLINK(two->mode))) {
		const char *del = diff_get_color_opt(o, DIFF_FILE_OLD);
		const char *add = diff_get_color_opt(o, DIFF_FILE_NEW);
		show_submodule_inline_diff(o->file, one->path ? one->path : two->path,
				line_prefix,
				&one->oid, &two->oid,
				two->dirty_submodule,
				meta, del, add, reset, o);
		return;
			if (!oidcmp(&one->oid, &two->oid)) {
	same_contents = !oidcmp(&one->oid, &two->oid);
		hashcpy(spec->oid.hash, sha1);
		spec->oid_valid = sha1_valid;
	/*
	 * Similarly, if we'd have to convert the file contents anyway, that
	 * makes the optimization not worthwhile.
	 */
	if (!want_file && would_convert_to_git(name))
		return 0;

	if (hashcmp(sha1, ce->oid.hash) || !S_ISREG(ce->ce_mode))
	strbuf_addf(&buf, "Subproject commit %s%s\n",
		    oid_to_hex(&s->oid), dirty);
	if (!s->oid_valid ||
	    reuse_worktree_file(s->path, s->oid.hash, 0)) {
			type = sha1_object_info(s->oid.hash, &s->size);
				die("unable to read %s",
				    oid_to_hex(&s->oid));
		s->data = read_sha1_file(s->oid.hash, &type, &s->size);
			die("unable to read %s", oid_to_hex(&s->oid));
			   const struct object_id *oid,
	oid_to_hex_r(temp->hex, oid);
	    (!one->oid_valid ||
	     reuse_worktree_file(name, one->oid.hash, 1))) {
				       (one->oid_valid ?
					&one->oid : &null_oid),
				       (one->oid_valid ?
			if (!one->oid_valid)
				sha1_to_hex_r(temp->hex, one->oid.hash);
			       &one->oid, one->mode);
	if (one && two && oidcmp(&one->oid, &two->oid)) {
			    find_unique_abbrev(one->oid.hash, abbrev));
		strbuf_add_unique_abbrev(msg, two->oid.hash, abbrev);
		if (!one->oid_valid) {
				oidclr(&one->oid);
			if (index_path(one->oid.hash, one->path, &st, 0))
		oidclr(&one->oid);
	options->ws_error_highlight = ws_error_highlight_default;
	if (diff_indent_heuristic)
		DIFF_XDL_SET(options, INDENT_HEURISTIC);
	else if (diff_compaction_heuristic)
		die(_("--name-only, --name-status, --check and -s are mutually exclusive"));
				die_want_option("--stat-width");
				die_want_option("--stat-name-width");
				die_want_option("--stat-graph-width");
				die_want_option("--stat-count");
static int parse_ws_error_highlight_opt(struct diff_options *opt, const char *arg)
	int val = parse_ws_error_highlight(arg);
	if (val < 0) {
		error("unknown value after ws-error-highlight=%.*s",
		      -1 - val, arg);
		return 0;
	else if (!strcmp(arg, "--indent-heuristic")) {
		DIFF_XDL_SET(options, INDENT_HEURISTIC);
		DIFF_XDL_CLR(options, COMPACTION_HEURISTIC);
	} else if (!strcmp(arg, "--no-indent-heuristic"))
		DIFF_XDL_CLR(options, INDENT_HEURISTIC);
	else if (!strcmp(arg, "--compaction-heuristic")) {
		DIFF_XDL_CLR(options, INDENT_HEURISTIC);
	} else if (!strcmp(arg, "--no-compaction-heuristic"))
		options->submodule_format = DIFF_SUBMODULE_LOG;
		return parse_ws_error_highlight_opt(options, arg);
	else if ((argcount = parse_long_opt("line-prefix", av, &optarg))) {
		options->line_prefix = optarg;
		options->line_prefix_length = strlen(options->line_prefix);
		graph_setup_line_prefix(options);
		return argcount;
	}
		if (options->use_color != GIT_COLOR_ALWAYS)
			options->use_color = GIT_COLOR_NEVER;
/*
 * This is different from find_unique_abbrev() in that

	/*
	 * In well-behaved cases, where the abbbreviated result is the
	 * same as the requested length, append three dots after the
	 * abbreviation (hence the whole logic is limited to the case
	 * where abblen < 37); when the actual abbreviated result is a
	 * bit longer than the requested length, we reduce the number
	 * of dots so that they match the well-behaved ones.  However,
	 * if the actual abbreviation is longer than the requested
	 * length by more than three, we give up on aligning, and add
	 * three dots anyway, to indicate that the output is not the
	 * full object name.  Yes, this may be suboptimal, but this
	 * appears only in "diff --raw --abbrev" output and it is not
	 * worth the effort to change it now.  Note that this would
	 * likely to work fine when the automatic sizing of default
	 * abbreviation length is used--we would be fed -1 in "len" in
	 * that case, and will end up always appending three-dots, but
	 * the automatic sizing is supposed to give abblen that ensures
	 * uniqueness across all objects (statistically speaking).
	 */
			diff_unique_abbrev(p->one->oid.hash, opt->abbrev));
		fprintf(opt->file, "%s ",
			diff_unique_abbrev(p->two->oid.hash, opt->abbrev));
	if (one->oid_valid && two->oid_valid &&
	    !oidcmp(&one->oid, &two->oid) &&
	if (!one->oid_valid && !two->oid_valid)
		s->oid_valid ? oid_to_hex(&s->oid) : "");
		else if (oidcmp(&p->one->oid, &p->two->oid) ||
			 is_null_oid(&p->one->oid))
static int diff_get_patch_id(struct diff_options *options, unsigned char *sha1, int diff_header_only)
		if (diff_header_only)
			continue;

		if (fill_mmfile(&mf1, p->one) < 0 ||
		    fill_mmfile(&mf2, p->two) < 0)
			return error("unable to read files to diff");

			git_SHA1_Update(&ctx, oid_to_hex(&p->one->oid),
					40);
			git_SHA1_Update(&ctx, oid_to_hex(&p->two->oid),
					40);
int diff_flush_patch_id(struct diff_options *options, unsigned char *sha1, int diff_header_only)
	int result = diff_get_patch_id(options, sha1, diff_header_only);
N_("inexact rename detection was skipped due to too many files.");
N_("only found copies from modified paths due to too many files.");
N_("you may want to set your %s variable to at least "
   "%d and retry the command.");
		warning(_(degrade_cc_to_c_warning));
		warning(_(rename_limit_warning));
		warning(_(rename_limit_advice), varname, needed);
	    (p->one->oid_valid && p->two->oid_valid) ||
	QSORT(q->queue, q->nr, diffnamecmp);
	if (driver->textconv_cache && df->oid_valid) {
		*outbuf = notes_cache_get(driver->textconv_cache,
					  df->oid.hash,
	if (driver->textconv_cache && df->oid_valid) {
		notes_cache_put(driver->textconv_cache, df->oid.hash, *outbuf,